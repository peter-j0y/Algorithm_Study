data class Truck (val weight: Int, var cnt: Int = 0)

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        val bridge = ArrayDeque<Truck>()
        val trucks = ArrayDeque<Truck>()

        trucks.addAll(truck_weights.map { Truck(it, 0) })

        var answer = 0
        while (true) {
            if (bridge.size < bridge_length && trucks.isNotEmpty()){
                if (bridge.sumOf { it.weight } + trucks[0].weight <= weight)
                    bridge.addLast(trucks.removeFirst())
            }

            answer++
            bridge.forEach { it.cnt++ }


            while (bridge.isNotEmpty() && bridge[0].cnt == bridge_length) {
                bridge.removeFirst()
            }

            if (trucks.isEmpty() && bridge.isEmpty())
                return ++answer
        }

    }
}